#include "MCPlayer.h"
#include "Engine/World.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PawnMovementComponent.h"


AMCPlayer::AMCPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	springArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	springArmComponent->SetupAttachment(RootComponent);
	springArmComponent->bUsePawnControlRotation = true;

	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	cameraComponent->SetupAttachment(springArmComponent);

	GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;
	GetMovementComponent()->GetNavAgentPropertiesRef().bCanJump = true;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
}

void AMCPlayer::BeginPlay()
{
	Super::BeginPlay();


}

void AMCPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMCPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMCPlayer::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMCPlayer::OnMoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &AMCPlayer::OnLookVertical);
	PlayerInputComponent->BindAxis("LookTurn", this, &AMCPlayer::OnLookHorizontal);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMCPlayer::OnStartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AMCPlayer::OnEndCrouch);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMCPlayer::OnStartJump);

}

void AMCPlayer::OnMoveForward(float p_val)
{
    if (p_val == 0.0f)
        return;

    FRotator currentRotation = this->GetControlRotation();
    FRotator normalizeRotation(0.0f, currentRotation.Yaw, 0.0f);

    FVector forwardVector = FRotationMatrix(normalizeRotation).GetUnitAxis(EAxis::X);

	AddMovementInput(forwardVector, p_val, false);
}

void AMCPlayer::OnMoveRight(float p_val)
{
    if (p_val == 0.0f)
        return;

    FRotator currentRotation = this->GetControlRotation();
    FRotator normalizeRotation(0.0f, currentRotation.Yaw, 0.0f);

    FVector rightVector = FRotationMatrix(normalizeRotation).GetUnitAxis(EAxis::Y);

    AddMovementInput(rightVector, p_val, false);
}

void AMCPlayer::OnLookVertical(float p_val) 
{
    AddControllerPitchInput(GetWorld()->GetDeltaSeconds() * p_val * m_verticalSensitivity);
}

void AMCPlayer::OnLookHorizontal(float p_val)
{
    AddControllerYawInput(GetWorld()->GetDeltaSeconds() * p_val * m_horizontalSensitivity);
}