#include "TargetActor.h"
#include "Kismet/GameplayStatics.h"
#include "TargetGameMode.h"

void ATargetActor::NotifyHit(
    UPrimitiveComponent* MyComp,
    AActor* Other,
    UPrimitiveComponent* OtherComp,
    bool bSelfMoved,
    FVector HitLocation,
    FVector HitNormal,
    FVector NormalImpulse,
    const FHitResult& Hit)
{
    Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

    ATargetGameMode* GM = Cast<ATargetGameMode>(UGameplayStatics::GetGameMode(this));

    if (GM)
    {
        GM->AddScore();
    }

    Destroy(); // remove target after hit
}