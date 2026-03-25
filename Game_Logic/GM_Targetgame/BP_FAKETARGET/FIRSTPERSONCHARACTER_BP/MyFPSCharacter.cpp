#include "MyFPSCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "Animation/AnimInstance.h"
#include "NiagaraFunctionLibrary.h"

void AMyFPSCharacter::Fire()
{
    // 🎬 PLAY ANIMATION
    if (FireMontage)
    {
        UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
        if (AnimInstance)
        {
            AnimInstance->Montage_Play(FireMontage);
        }
    }

    // 📍 GET MUZZLE TRANSFORM
    FVector Location = MuzzlePoint->GetComponentLocation();
    FRotator Rotation = MuzzlePoint->GetComponentRotation();

    FTransform SpawnTransform;
    SpawnTransform.SetLocation(Location);
    SpawnTransform.SetRotation(Rotation.Quaternion());

    // 🔫 SPAWN BULLET
    if (BulletClass)
    {
        GetWorld()->SpawnActor<AActor>(
            BulletClass,
            SpawnTransform,
            FActorSpawnParameters()
        );
    }

    // 🔊 PLAY SOUND
    if (FireSound)
    {
        UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
    }

    // 💥 SPAWN VFX
    if (MuzzleVFX)
    {
        UNiagaraFunctionLibrary::SpawnSystemAttached(
            MuzzleVFX,
            MuzzlePoint,
            NAME_None,
            FVector::ZeroVector,
            FRotator::ZeroRotator,
            EAttachLocation::KeepRelativeOffset,
            true
        );
    }
}