#pragma region REDEFINITION

#ifndef MESSAGETAIL_H
#define MESSAGETAIL_H

#pragma endregion REDEFINITION

#pragma region CONSTANS

#define END_CONTENT "_END"

#pragma endregion CONSTANS

#pragma region INCLUDES

#include "MessageBase.h"

#pragma endregion INCLUDES

class MessageTail :
	public Message
{

#pragma region PUBLIC

public:

#pragma region PUBLIC_FUNCTIONS

	/* Constructors */
	MessageTail():
		Message(END, sizeof(END_CONTENT)) 
	{ }

	/* Destructors */
	~MessageTail()
	{ }

	/* Public Accesors */
	std::string getContent()
	{
		return END_CONTENT;
	}

	/* Override virtual functions */
	std::string MessageTail::toString();

	bool MessageTail::isTail()
	{
		return true;
	}

#pragma endregion PUBLIC_FUNCTIONS

#pragma endregion PUBLIC	
};

#endif

