#include "SwordWeapon.h"


ASwordWeapon::ASwordWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	swordMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMeshComponent"));
	RootComponent = swordMeshComponent;
}

void ASwordWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASwordWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

