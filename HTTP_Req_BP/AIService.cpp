#include "AIService.h"

void UAIService::EvaluateCode(const FString& Code, FOnAIResponse Callback)
{
    ResponseCallback = Callback;

    TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();

    Request->SetURL("https://your-api-url.com/evaluate"); // 🔥 your endpoint
    Request->SetVerb("POST");
    Request->SetHeader("Content-Type", "application/json");

    FString Body = FString::Printf(TEXT("{\"code\":\"%s\"}"), *Code);
    Request->SetContentAsString(Body);

    Request->OnProcessRequestComplete().BindUObject(this, &UAIService::OnResponseReceived);
    Request->ProcessRequest();
}

void UAIService::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
    if (!bSuccess || !Response.IsValid())
    {
        ResponseCallback.ExecuteIfBound("error");
        return;
    }

    FString ResponseString = Response->GetContentAsString();
    ResponseCallback.ExecuteIfBound(ResponseString);
}