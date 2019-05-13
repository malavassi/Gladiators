// Fill out your copyright notice in the Description page of Project Settings.


#include "Gladiator.h"
#include "ConstructorHelpers.h"
#include "GladiatorAIController.h"
#include "SimpleArrow.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/AnimBlueprint.h"
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

int AGladiator::cont = 0;
// Sets default values
AGladiator::AGladiator()
{
	ded = false;
	//AutoPossessPlayer = EAutoReceiveInput::Player0;
	id = AGladiator::cont;
	AGladiator::cont++;
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//animations = CreateDefaultSubobject<UMyAnimInstance>(TEXT("AnimInstance"));
	//animations->SetupAttachment(RootComponent);

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamra"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	resistencia = 0;

	OnActorHit.AddDynamic(this, &AGladiator::OnHit);

	// Mesh esqueletico
	mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GLAD"));
	mesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// Lo busco
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> meshAsset(TEXT("/Game/Mannequin/Character/Mesh/uriel_a_plotexia.uriel_a_plotexia"));

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

	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> animAsset(TEXT("/Game/Mannequin/Animations/GladAnim_BP.GladAnim_BP"));
	mesh->SetAnimInstanceClass(animAsset.Object->GeneratedClass);

	ConstructorHelpers::FObjectFinder<UParticleSystem> faya(TEXT("ParticleSystem'/Game/FirePJ.FirePJ'"));
	
	fayafaya = faya.Object;


}

void AGladiator::setResistencia(int cantidad) {
	resistencia = cantidad;
	ready = true;
}

bool AGladiator::getReady() {
	return ready;
}

void AGladiator::bajarResistencia(int cantidad) {
	resistencia -= cantidad;
	// Encender en fuego alv
	UGameplayStatics::SpawnEmitterAttached(
     fayafaya,                   //particle system
     mesh,      //mesh to attach to
     FName("Torso"),   //socket name
     FVector(0,0,64),  //location relative to socket
     FRotator(0,0,0), //rotation 
     EAttachLocation::KeepRelativeOffset, 
     true //will be deleted automatically
	 );

	if (resistencia<=0) {
		print("Ay perrillo me mori");
		if (animations) {
			animations->dying = true;
			ded = true;
			//Destroy();
		}
		else {
			print("Bad pointer animations");
		}
		
		//Destroy();
	}
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
	animations = Cast<UMyAnimInstance>(mesh->GetAnimInstance());
}

void AGladiator::setCamara() {
	APlayerController* ActivePC = UGameplayStatics::GetPlayerController(this, 0);
	if (ActivePC && FollowCamera) {
		ActivePC->SetViewTarget(this);
	}
}

// Called every frame
void AGladiator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ded) {
		//print("Entrra");
		if (animations->GetRelevantAnimTimeRemaining(0,2)<0.1) {
			mesh->bPauseAnims = true;
		}
	}

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
	if (id==1) {
		//print("1 pressed");
		//InputComponent->BindAction("Cam1", IE_Pressed, this, &AGladiator::setCamara);
	}
	else {
		//print("1");
		InputComponent->BindAction("Cam2", IE_Pressed, this, &AGladiator::setCamara);
	}

}

