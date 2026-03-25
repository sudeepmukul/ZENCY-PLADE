#include "CodeTerminalWidget.h"

void UCodeTerminalWidget::SubmitCode(const FString& Code)
{
    OnCodeSubmitted.Broadcast(Code);
}