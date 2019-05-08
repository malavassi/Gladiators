// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "MyCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class GLADIATORSGBP_API AMyCameraActor : public ACameraActor
{
	GENERATED_BODY()
public:
	void setCam();
	
};
