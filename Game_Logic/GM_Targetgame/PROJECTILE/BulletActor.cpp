#include "BulletActor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

ABulletActor::ABulletActor()
{
    PrimaryActorTick.bCanEverTick = false;

    // 🔵 Collision
    Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
    RootComponent = Collision;

    Collision->SetNotifyRigidBodyCollision(true);
    Collision->SetSimulatePhysics(false);

    // 🚀 Movement
    Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
    Movement->InitialSpeed = 3000.f;
    Movement->MaxSpeed = 3000.f;
    Movement->bRotationFollowsVelocity = true;
    Movement->bShouldBounce = false;
}

void ABulletActor::BeginPlay()
{
    Super::BeginPlay();

    Collision->OnComponentHit.AddDynamic(this, &ABulletActor::OnHit);
}

void ABulletActor::OnHit(
    UPrimitiveComponent* HitComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    FVector NormalImpulse,
    const FHitResult& Hit)
{
    if (!OtherComp) return;

    // 🧠 Check physics
    if (OtherComp->IsSimulatingPhysics())
    {
        FVector Velocity = Movement->Velocity;

        // 💥 Apply impulse
        OtherComp->AddImpulseAtLocation(
            Velocity * ImpulseStrength,
            GetActorLocation()
        );
    }

    // 💀 Destroy bullet
    Destroy();
}