// Fill out your copyright notice in the Description page of Project Settings.


#include "Gladiator.h"
#include "ConstructorHelpers.h"

// Sets default values
AGladiator::AGladiator()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("Constructor"));

	// Lo siguiente solo puede estar en un constructor, nada mas!!
	USkeletalMeshComponent* mesh = CreateDefaultSubobject < USkeletalMeshComponent>(TEXT("ASkeletalmesh"));
	//mesh->SetStaticMesh(StaticMesh'/Game/Geometry/Meshes/1M_Cube_Chamfer.1M_Cube_Chamfer');

	mesh->SetupAttachment(RootComponent);


	// Go find that shiet
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> meshAsset(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin"));

	if (meshAsset.Succeeded()){
		// Set the shiet
		UE_LOG(LogTemp, Warning, TEXT("Getting Mesh"));
		mesh->SetSkeletalMeshWithoutResettingAnimation(meshAsset.Object);
		mesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
		mesh->SetWorldScale3D(FVector(1.f));
	}
}

// Called when the game starts or when spawned
void AGladiator::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGladiator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGladiator::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

