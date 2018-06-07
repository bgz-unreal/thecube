#include "Hitpoints.h"
#include "Components/ActorComponent.h"

UHitpoints::UHitpoints()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHitpoints::BeginPlay()
{
	Super::BeginPlay();

	hitpointValue = 100.0f;
	
	AActor* owner = GetOwner();
	if (owner)
	{
		owner->OnTakeAnyDamage.AddDynamic(this, &UHitpoints::ProcessTakeDamage);
	}
}

void UHitpoints::ProcessTakeDamage(
	AActor * DamagedActor, 
	float Damage, 
	const UDamageType * DamageType, 
	AController * InstigatedBy, 
	AActor * DamageCauser)
{
	if (Damage <= 0.0f)
		return;

	hitpointValue = FMath::Clamp(hitpointValue - Damage, 0.0f, defaultHitpointValue);

	UE_LOG(LogTemp, Log, TEXT("Health Changed: %s"), *FString::SanitizeFloat(hitpointValue));

}