UPROPERTY()
class UAIService* AIService;

void EvaluateCodeWithAI(const FString& Code);
void OnAIResponse(FString Response);