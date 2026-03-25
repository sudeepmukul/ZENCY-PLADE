#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletActor.generated.h"

UCLASS()
class YOURPROJECT_API ABulletActor : public AActor
{
    GENERATED_BODY()

public:
    ABulletActor();

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnHit(
        UPrimitiveComponent* HitComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        FVector NormalImpulse,
        const FHitResult& Hit
    );

private:

    // 💥 Collision
    UPROPERTY(VisibleAnywhere)
    class USphereComponent* Collision;

    // 🚀 Movement
    UPROPERTY(VisibleAnywhere)
    class UProjectileMovementComponent* Movement;

    // 💪 Force multiplier
    UPROPERTY(EditAnywhere)
    float ImpulseStrength = 100.0f;
};