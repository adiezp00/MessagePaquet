#pragma region REDEFINITION

#ifndef MESSAGEBASE_H
#define MESSAGEBASE_H

#pragma endregion REDEFINITION

#pragma region INCLUDE

#include <string>

#include "MessageTypes.h"

#pragma endregion INCLUDE

class Message
{

#pragma region PUBLIC

public:

#pragma region PUBLIC_FUNCTIONS

	/* Constructors */
	Message():
		m_enumType(NONE),
		m_iSize(0)
	{ }

	Message(MessageTypes type, int size):
		m_enumType(type),
		m_iSize(size)
	{ }

	Message(Message* nextRef, MessageTypes type, int size) :
		m_mRefNext(nextRef),
		m_enumType(type),
		m_iSize(size)
	{ }


	/* Destructor */
	~Message()
	{ }

	/* Public accessors */

	MessageTypes getType()
	{
		return m_enumType;
	}

	int getSize()
	{
		return m_iSize;
	}

	/* Public mutators */
	void setType(MessageTypes newType)
	{
		m_enumType = newType;
	}

	void setSize(int newSize)
	{
		m_iSize = newSize;
	}

	/* Virtual functions */

	virtual std::string toString() = 0;

	virtual bool isTail() = 0;

#pragma endregion PUBLIC_FUNCTIONS

#pragma endregion PUBLIC

#pragma region PROTECTED

protected:

#pragma region PROTECTED_VARIABLES

	/* Type of this part of the message */
	MessageTypes m_enumType;
	
	/* Size of this part of the message */
	int m_iSize;

#pragma endregion PROTECTED_VARIABLES

#pragma endregion PROTECTED

#pragma region PRIVATE

private:

#pragma region PRIVATE_VARIABLES

	/* Referencie to the next part of the message */
	Message *m_mRefNext;	///TODO Is a problem that MessageContent has more variables??

#pragma endregion PRIVATE_VARIABLES

#pragma region PRIVATE_FUNCTIONS

	/* Private Accesors */
	Message* getNextRef()
	{
		return m_mRefNext;
	}

	/* Private Mutators */
	void setNextRef(Message* newRef)
	{
		m_mRefNext = newRef;
	}

#pragma endregion PRIVATE_FUNCTIONS

#pragma endregion PRIVATE

};

#endif