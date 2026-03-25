#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (MenuWidgetClass)
    {
        // 🧱 Create Widget
        MenuWidget = CreateWidget<UUserWidget>(this, MenuWidgetClass);

        if (MenuWidget)
        {
            // 📺 Add to screen
            MenuWidget->AddToViewport();

            // 🎮 UI Input Mode
            FInputModeUIOnly InputMode;
            InputMode.SetWidgetToFocus(MenuWidget->TakeWidget());
            InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

            SetInputMode(InputMode);

            // 🖱️ Show cursor
            bShowMouseCursor = true;
        }
    }
}