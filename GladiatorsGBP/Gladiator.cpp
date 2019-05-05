// Fill out your copyright notice in the Description page of Project Settings.


#include "Gladiator.h"
#include "ConstructorHelpers.h"
#include "GladiatorAIController.h"
#include "SimpleArrow.h"
#include "Animation/AnimBlueprint.h"
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

// Sets default values
AGladiator::AGladiator()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OnActorHit.AddDynamic(this, &AGladiator::OnHit);

	// Mesh esqueletico
	USkeletalMeshComponent *mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GLAD"));
	mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// Lo busco
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> meshAsset(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin"));

	if (meshAsset.Succeeded()) {  // Si lo encuentro, lo seteo
		mesh->SetSkeletalMesh(meshAsset.Object);
		mesh->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
		mesh->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
		mesh->SetWorldScale3D(FVector(1.f, 1.f, 1.f));
	}

	// Poseido por una AI desde que aparece
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	// AI que lo posee es AGladiatorAIController
	AIControllerClass = AGladiatorAIController::StaticClass();

	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> animAsset(TEXT("/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP"));
	mesh->SetAnimInstanceClass(animAsset.Object->GeneratedClass);


}

void AGladiator::setChars(int res, int iq, int cF, int TS, int TI, int edad, int prob, int genEsperadas)
{
	resistencia = res;
	inteligenciaEmocional = iq;
	condicionFisica = cF;
	this->edad = edad;
	this->prob = prob;
	this->genEsperadas = genEsperadas;
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

void AGladiator::OnHit(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult & Hit)
{
	ASimpleArrow* flecha = Cast<ASimpleArrow>(OtherActor);
	if (flecha) { // Si se logro
		print("Me golpea una flecha");
	}
}

// Called to bind functionality to input
void AGladiator::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	

}

