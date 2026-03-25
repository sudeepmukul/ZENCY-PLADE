#include "FakeTargetActor.h"
#include "Kismet/GameplayStatics.h"
#include "TargetGameMode.h"

void AFakeTargetActor::HandleHit(AActor* OtherActor)
{
    // 💥 Still react physically (optional)
    if (GeometryCollection)
    {
        GeometryCollection->SetSimulatePhysics(true);
    }

    // 🚫 Disable collision
    Box->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    // ❌ PENALTY
    ATargetGameMode* GM = Cast<ATargetGameMode>(UGameplayStatics::GetGameMode(this));
    if (GM)
    {
        GM->DecreaseScore(1); // YOU MUST ADD THIS FUNCTION
    }

    // 🔴 Wrong feedback
    GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Wrong Target!"));

    if (WrongSound)
    {
        UGameplayStatics::PlaySound2D(this, WrongSound);
    }
}