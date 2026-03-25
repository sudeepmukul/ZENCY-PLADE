#include "TargetActor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModeBase.h"
#include "TargetGameMode.h"

ATargetActor::ATargetActor()
{
    PrimaryActorTick.bCanEverTick = false;

    // 📦 Box collider
    Box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));
    RootComponent = Box;

    Box->SetNotifyRigidBodyCollision(true);
    Box->SetSimulatePhysics(false);

    // 💥 Geometry (fracture)
    GeometryCollection = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Geometry"));
    GeometryCollection->SetupAttachment(Box);
}

void ATargetActor::BeginPlay()
{
    Super::BeginPlay();

    // 🔥 Bind hit event
    Box->OnComponentHit.AddDynamic(this, &ATargetActor::OnHit);
}

void ATargetActor::OnHit(
    UPrimitiveComponent* HitComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    FVector NormalImpulse,
    const FHitResult& Hit)
{
    if (bIsHit) return;

    // 🎯 Check if bullet hit
    if (OtherActor && OtherActor->ActorHasTag("Bullet"))
    {
        bIsHit = true;

        // 💥 Enable physics (fall effect)
        if (GeometryCollection)
        {
            GeometryCollection->SetSimulatePhysics(true);
        }

        // 🚫 Disable collision
        Box->SetCollisionEnabled(ECollisionEnabled::NoCollision);

        // 🧠 Add Score
        ATargetGameMode* GM = Cast<ATargetGameMode>(UGameplayStatics::GetGameMode(this));
        if (GM)
        {
            GM->AddScore();
        }

        // 🖨️ Debug
        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Correct Hit!"));

        // 🔊 Sound
        if (HitSound)
        {
            UGameplayStatics::PlaySound2D(this, HitSound);
        }
    }
}
