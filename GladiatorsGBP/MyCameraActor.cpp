// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCameraActor.h"
#include "Kismet/GameplayStatics.h"


void AMyCameraActor::setCam(){
	APlayerController* ActivePC = UGameplayStatics::GetPlayerController(this, 0);
	if (ActivePC) {
		ActivePC->SetViewTarget(this);
	}
}