#pragma region REDEFINITION

#ifndef MESSAGECONTENT_H
#define MESSAGECONTENT_H

#pragma endregion REDEFINITION

#pragma region INCLUDES

#include "MessageBase.h"

#pragma endregion INCLUDES

class MessageContentInt :
	public Message
{

#pragma region PUBLIC

public:

#pragma region PUBLIC_FUNCTIONS

	/* Constructors */
	MessageContentInt():
		Message(INT, sizeof(int))
	{ }

	MessageContentInt(int content):
		m_iContent(content),
		Message(INT, sizeof(content))
	{ }

	/* Destructors */
	~MessageContentInt() 
	{ }

	/* Public Accesors */
	int getContent()
	{
		return m_iContent;
	}

	Message* getNextRef()
	{
		return m_mRefNext;
	}

	/* Public Mutators */
	void setContent(int newContent)
	{
		m_iContent = newContent;
		setSize(sizeof(newContent));
	}

	void setNextRef(Message* newRef)
	{
		m_mRefNext = newRef;
	}

	/* Override functions */
	std::string MessageContentInt::toString();

	bool MessageContentInt::isTail()
	{
		return false;
	}

#pragma endregion PUBLIC_FUNCTIONS

#pragma endregion PUBLIC

#pragma region PRIVATE

private:

#pragma region PRIVATE_VARIABLES

	/* Content of the message part */
	int m_iContent;

	/* Referencie to the next part of the message */
	Message *m_mRefNext;	///TODO Is a problem that MessageContent has more variables??
	// Maybe we can use void* variable and templates??

#pragma endregion PRIVATE_VARIABLES

#pragma endregion PRIVATE

};

#endif