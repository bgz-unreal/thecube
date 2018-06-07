#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Hitpoints.generated.h"


UCLASS( ClassGroup=(COOP), meta=(BlueprintSpawnableComponent) )
class HAYDEE_API UHitpoints : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHitpoints();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void ProcessTakeDamage(
		AActor* DamagedActor, 
		float Damage, 
		const class UDamageType* DamageType, 
		class AController* InstigatedBy, 
		AActor* DamageCauser);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HealthComponent")
	float hitpointValue;

	float defaultHitpointValue;

};
