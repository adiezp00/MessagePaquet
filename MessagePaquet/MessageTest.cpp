#include "MessageBase.h"
#include "MessageContent.h"
#include "MessageTail.h"

#include <iostream>

int main()
{
	Message* root = new MessageContentInt(123);
	Message* nextPart = new MessageContentInt(456);
	Message* end = new MessageTail();
	((MessageContentInt*) root)->setNextRef(nextPart);
	((MessageContentInt*) nextPart)->setNextRef(end);
	std::cout << root->toString();
}