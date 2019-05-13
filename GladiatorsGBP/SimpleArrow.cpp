// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleArrow.h"
#include "ConstructorHelpers.h"
#include "CoreMinimal.h"

#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"

//Debugs
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))


// Sets default values
ASimpleArrow::ASimpleArrow(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	
	target = FVector(0, 0, 0);

	currentPos = GetActorLocation();
	speed = 1.f;
	targetAq = false;



	// Lo siguiente solo puede estar en un constructor, nada mas!!
	 mesh = CreateDefaultSubobject < UStaticMeshComponent>(TEXT("Amesh"));
	//mesh->SetStaticMesh(StaticMesh'/Game/Geometry/Meshes/1M_Cube_Chamfer.1M_Cube_Chamfer');

	RootComponent = mesh;

	//RootComponent = mesh;


	// Go find that shiet
	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("/Game/Geometry/Arrow_SM.Arrow_SM"));

	if (meshAsset.Succeeded()) {
		// Set the shiet
		UE_LOG(LogTemp, Warning, TEXT("Arrow created"));
		mesh->SetStaticMesh(meshAsset.Object);
		mesh->SetWorldScale3D(FVector(30.f,30.f,12.f));
		mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		mesh->SetSimulatePhysics(true);

		OnActorHit.AddDynamic(this, &ASimpleArrow::OnHit);
		OnActorBeginOverlap.AddDynamic(this, &ASimpleArrow::OnOverlapBegin);

	}

}


UStaticMeshComponent* ASimpleArrow::getMesh() {
	return mesh;
}

// Called when the game starts or when spawned
void ASimpleArrow::BeginPlay()
{
	Super::BeginPlay();
	//DrawDebugSphere(GetWorld(), GetActorLocation(), 20.0f, 50, FColor::Purple, true, -1, 0, 2);
}

void ASimpleArrow::setType(int type) {
	this->type = type;
	// Recalcule mesh

}

void ASimpleArrow::setTarget(FVector target) {
	this->target = target;
	targetAq = true;
}

// Called every frame
void ASimpleArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), target));
	if (target == GetActorLocation()) {
		Destroy();
	}
}

void ASimpleArrow::OnHit(AActor * SelfActor, class AActor * OtherActor, FVector NormalImpulse, const FHitResult &Hit){
	print("hit");
	AGladiator* a = Cast<AGladiator>(OtherActor);
	if(a){
		a->bajarResistencia(5);
	}
	Destroy();
}

void ASimpleArrow::OnOverlapBegin(AActor * OverlappedActor, AActor * OtherActor)
{
	// check if Actors do not equal nullptr and that 

	ASimpleArrow* flechilla = Cast<ASimpleArrow>(OtherActor);
	if (OtherActor && (OtherActor != this)) {
		// print to screen using above defined method when actor enters trigger box
		print("Overlap Begin hit");
		printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
	}
}

