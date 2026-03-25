#pragma once

#include "CoreMinimal.h"
#include "TargetActor.h"
#include "FakeTargetActor.generated.h"

UCLASS()
class YOURPROJECT_API AFakeTargetActor : public ATargetActor
{
    GENERATED_BODY()

protected:
    virtual void HandleHit(AActor* OtherActor) override;

private:
    UPROPERTY(EditAnywhere)
    USoundBase* WrongSound;
};