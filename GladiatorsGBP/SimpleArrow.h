// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleArrow.generated.h"

UCLASS()
class GLADIATORSGBP_API ASimpleArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASimpleArrow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void setTarget(FVector target);

	UFUNCTION()
		USkeletalMeshComponent* getMesh();
	UFUNCTION()
		void OnHit(AActor * SelfActor, class AActor * OtherActor, FVector NormalImpulse, const FHitResult &Hit);
private:
	UPROPERTY()
		USkeletalMeshComponent* mesh;
	UPROPERTY()
	FVector target;
	UPROPERTY()
	float tX;
	UPROPERTY()
	float tY;
	UPROPERTY()
	float tZ;
	UPROPERTY()
	bool targetAq;
	UPROPERTY()
	FVector currentPos;
	UPROPERTY()
	float speed;

};
