#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwordWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class HAYDEE_API ASwordWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ASwordWeapon();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* swordMeshComponent;

public:	
	virtual void Tick(float DeltaTime) override;

	
	
};
