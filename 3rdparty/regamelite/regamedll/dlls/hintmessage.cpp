#include "precompiled.h"

CHintMessage::CHintMessage(const char *hintString, bool isHint, CUtlVector<const char *> *args, float duration)
{
	m_hintString = CloneString(hintString);
	m_duration = duration;
	m_isHint = isHint;

	if (args)
	{
		for (int i = 0; i < args->Count(); i++)
			m_args.AddToTail(CloneString((*args)[i]));
	}
}

CHintMessage::~CHintMessage()
{
	m_args.PurgeAndDeleteArrays();

	if (m_hintString)
	{
		delete[] m_hintString;
		m_hintString = NULL;
	}
}

void CHintMessage::Send(CBaseEntity *client)
{
	UTIL_ShowMessageArgs(m_hintString, client, &m_args, m_isHint);
}

void CHintMessageQueue::Reset()
{
	m_tmMessageEnd = 0;
	m_messages.PurgeAndDeleteElements();
}

void CHintMessageQueue::Update(CBaseEntity *client)
{
	if (gpGlobals->time <= m_tmMessageEnd)
		return;

	if (!m_messages.Count())
		return;

	CHintMessage *msg = m_messages[0];
	m_tmMessageEnd = gpGlobals->time + msg->GetDuration();
	msg->Send(client);
	delete msg;
	m_messages.Remove(0);
}

bool CHintMessageQueue::AddMessage(const char *message, float duration, bool isHint, CUtlVector<const char *> *args)
{
	CHintMessage *msg = new CHintMessage(message, isHint, args, duration);
	m_messages.AddToTail(msg);

	return true;
}
