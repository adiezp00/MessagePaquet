#pragma region INCLUDES

#include "MessageContent.h"

#pragma endregion INCLUDES

#pragma region MESSAGE_CONTENT_INT_CLASS

std::string MessageContentInt::toString()
{
	return std::to_string(getContent()) + "__" + getNextRef()->toString();
}

#pragma endregion MESSAGE_CONTENT_INT_CLASS
