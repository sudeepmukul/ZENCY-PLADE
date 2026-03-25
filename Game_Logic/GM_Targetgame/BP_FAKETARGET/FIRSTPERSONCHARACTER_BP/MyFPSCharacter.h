#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyFPSCharacter.generated.h"

UCLASS()
class YOURPROJECT_API AMyFPSCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    void Fire();

protected:
    virtual void BeginPlay() override;

private:

    // 🔫 Bullet class
    UPROPERTY(EditAnywhere)
    TSubclassOf<AActor> BulletClass;

    // 🎬 Fire animation
    UPROPERTY(EditAnywhere)
    UAnimMontage* FireMontage;

    // 🔊 Sound
    UPROPERTY(EditAnywhere)
    USoundBase* FireSound;

    // 💥 VFX
    UPROPERTY(EditAnywhere)
    class UNiagaraSystem* MuzzleVFX;

    // 📍 Muzzle point
    UPROPERTY(VisibleAnywhere)
    class UArrowComponent* MuzzlePoint;
};