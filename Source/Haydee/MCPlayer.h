#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MCPlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class HAYDEE_API AMCPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AMCPlayer();

protected:
	virtual void BeginPlay() override;

	void OnMoveForward(float p_val);
	void OnMoveRight(float p_val);

    void OnLookVertical(float p_val);
    void OnLookHorizontal(float p_val);

	void OnStartCrouch() { Crouch();   }
	void OnEndCrouch()   { UnCrouch(); }
	void OnStartJump()   { Jump();     }
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* springArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* cameraComponent;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    AActor * owner;

    UPROPERTY(VisibleAnywhere)
    float m_verticalSensitivity = 45.0f;

    UPROPERTY(VisibleAnywhere)
    float m_horizontalSensitivity = 45.0f;
};
