#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetActor.generated.h"

UCLASS()
class YOURPROJECT_API ATargetActor : public AActor
{
    GENERATED_BODY()

public:
    ATargetActor();

protected:
    virtual void BeginPlay() override;

    // 💥 Hit event
    UFUNCTION()
    void OnHit(
        UPrimitiveComponent* HitComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        FVector NormalImpulse,
        const FHitResult& Hit
    );

private:
    // 🧱 Components
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Box;

    UPROPERTY(VisibleAnywhere)
    UPrimitiveComponent* GeometryCollection;

    // 🧠 State
    bool bIsHit = false;

    // 🔊 Sound
    UPROPERTY(EditAnywhere)
    class USoundBase* HitSound;
};