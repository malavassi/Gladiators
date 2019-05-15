// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"
#include "LinkedList.h"

#include "SimpleTower.generated.h"

class ACasilla1;
UCLASS()
class GLADIATORSGBP_API ASimpleTower : public AActor
{
	GENERATED_BODY()
	
public:	

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		UAnimMontage* FireAnimation;

	// Sets default values for this actor's properties
	ASimpleTower();

	UPROPERTY(VisibleAnywhere)
		int rot = 0;

	void Fire(AActor* Objective);

	UPROPERTY(VisibleAnywhere, Category="Tower")
	class USphereComponent* effect_area;
	
	UPROPERTY(VisibleAnywhere, Category="Tower")
	class UStaticMeshComponent* mesh;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	FHitResult WeaponTrace(const FVector& StartTrace, const FVector& EndTrace) const;
private:
	LinkedList<FVector> triggerBoxes; /** Posiciones relativas a mi torre donde van a estar mis triggerBoxes*/
	int type; /** Tipo de torre, 0 normal, 1 fuego, 2 explosivo*/
	int area; /** Area de efecto de la torre*/
	void setupTriggers(); /** Pone los triggers necesarios*/ 
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	void setType(int type);
	virtual void Tick(float DeltaTime) override;
	LinkedList<FVector> getTriggerBoxes();

};