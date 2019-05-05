// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleTower.h"
#include "ConstructorHelpers.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
// include draw debug helpers header file
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include <typeinfo>
#include "SimpleArrow.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))


// Sets default values
ASimpleTower::ASimpleTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SetActorScale3D(FVector(10.f,10.f,500.f));

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Torre"));

	
	//RootComponent = mesh;

	//effect_area = CreateDefaultSubobject<USphereComponent>(TEXT("Area"));
	//effect_area->InitSphereRadius(500.0f);
	//effect_area->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	//effect_area->SetCollisionProfileName(TEXT("Shoot!"));


	//effect_area->OnComponentBeginOverlap.AddDynamic(this, &ASimpleTower::OnOverlapBegin);
	//effect_area->OnComponentEndOverlap.AddDynamic(this, &ASimpleTower::OnOverlapEnd);
	//effect_area->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	//RootComponent = effect_area;

	mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (meshAsset.Succeeded()) {
		mesh->SetStaticMesh(meshAsset.Object);
		mesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
		mesh->SetWorldScale3D(FVector(1.f,1.f,8.f));
	}

	type = 0;
	area = 0;

	setupTriggers();
}

void ASimpleTower::setType(int type) {
	this->type = type;
	area = 1 + type;
	setupTriggers();

	// Recalcule mesh
}

void ASimpleTower::Fire(AActor *Objective)
{

	FHitResult OutHit;
	FVector Start = GetActorLocation();

	FVector End = Objective->GetActorLocation();
	FCollisionQueryParams CollisionParams;

	DrawDebugLine(GetWorld(), Start, End, FColor::Green, true);

	if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
	{
		if (OutHit.bBlockingHit)
		{
			print("Fire!");
			FActorSpawnParameters SpawnInfo;
			//FQuat myquat = FQuat(End-Start,1);
			

			ASimpleArrow* arrow = GetWorld()->SpawnActor<ASimpleArrow>(GetActorLocation()+(End-Start)/2, FRotator::ZeroRotator, SpawnInfo);
			
			
			arrow->setType(type);
			FRotator rotator = UKismetMathLibrary::FindLookAtRotation(arrow->GetActorLocation(), End);
			arrow->SetActorRotation(rotator + FRotator(FQuat(FVector(0, 1, 0), PI / 2)));

			arrow->getMesh()->AddForce((End-Start)*1000);
			
			arrow->setTarget(End);

		}
	}

	
}

void ASimpleTower::setupTriggers()
{
	//Setup triggerBoxes for simple
	triggerBoxes = LinkedList<FVector>();
	for (int i = -area; i <= area; i++) {
		for (int j = -area; j <= area; j++) {
			if (i == 0 && j == 0) {
			}
			else {
				triggerBoxes.push_back(FVector(i, j, 0));
			}
		}
	}
}

// Called when the game starts or when spawned
void ASimpleTower::BeginPlay()
{
	Super::BeginPlay();

	// Muestra el radio en pantalla
	//DrawDebugSphere(GetWorld(), GetActorLocation(), 500.0f, 50, FColor::Purple, true, -1, 0, 2);
	
}

// Called every frame
void ASimpleTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

LinkedList<FVector> ASimpleTower::getTriggerBoxes()
{
	return triggerBoxes;
}

void ASimpleTower::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	// check if Actors do not equal nullptr and that 
	if (OtherActor && (OtherActor != this) ) {
		// print to screen using above defined method when actor enters trigger box
		//printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
		Fire(OtherActor);
	}
}

void ASimpleTower::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	if (OtherActor && (OtherActor != this)) {
		// print to screen using above defined method when actor leaves trigger box
		print("Overlap Ended");
		printFString("%s has left the Trigger Box", *OtherActor->GetName());
	}
}

