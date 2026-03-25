#include "MyFPSCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// 🔥 your GameMode
#include "TargetGameMode.h"

AMyFPSCharacter::AMyFPSCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    bUseControllerRotationYaw = true;
    GetCharacterMovement()->bOrientRotationToMovement = false;
}

void AMyFPSCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (APlayerController* PC = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(DefaultMappingContext, 0);
        }
    }
}

void AMyFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyFPSCharacter::Move);
        Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyFPSCharacter::Look);
        Input->BindAction(JumpAction, ETriggerEvent::Started, this, &AMyFPSCharacter::StartJump);
        Input->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMyFPSCharacter::StopJump);

        // 🔫 SHOOT BIND
        Input->BindAction(ShootAction, ETriggerEvent::Started, this, &AMyFPSCharacter::Shoot);
    }
}

void AMyFPSCharacter::Move(const FInputActionValue& Value)
{
    FVector2D Input = Value.Get<FVector2D>();

    AddMovementInput(GetActorForwardVector(), Input.Y);
    AddMovementInput(GetActorRightVector(), Input.X);
}

void AMyFPSCharacter::Look(const FInputActionValue& Value)
{
    FVector2D Input = Value.Get<FVector2D>();

    AddControllerYawInput(Input.X);
    AddControllerPitchInput(Input.Y);
}

void AMyFPSCharacter::StartJump(const FInputActionValue& Value)
{
    Jump();
}

void AMyFPSCharacter::StopJump(const FInputActionValue& Value)
{
    StopJumping();
}

void AMyFPSCharacter::Shoot()
{
    APlayerController* PC = Cast<APlayerController>(Controller);
    if (!PC) return;

    FVector Start;
    FRotator Rotation;

    PC->GetPlayerViewPoint(Start, Rotation);

    FVector End = Start + (Rotation.Vector() * 10000.f);

    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    bool bHit = GetWorld()->LineTraceSingleByChannel(
        Hit,
        Start,
        End,
        ECC_Visibility,
        Params
    );

    // 🔴 Debug Line (laser beam vibes)
    DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.0f, 0, 1.0f);

    if (bHit)
    {
        AActor* HitActor = Hit.GetActor();

        if (HitActor)
        {
            // 🎯 Tell GameMode to increase score
            ATargetGameMode* GM = Cast<ATargetGameMode>(UGameplayStatics::GetGameMode(this));
            if (GM)
            {
                GM->AddScore();
            }

            // 💥 Destroy target
            HitActor->Destroy();
        }
    }
}