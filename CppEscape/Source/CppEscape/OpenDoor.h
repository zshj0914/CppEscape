// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPPESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float GetTotalMassOfActorsOnPlate();

	//void OpenDoor();

	//void CloseDoor();

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnClose;

private:
	/*UPROPERTY(EditAnywhere)
		float OpenAngle = -90.f;*/

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	/*UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 1.f;*/

	/*float LastDoorOpenTime;*/

	UPROPERTY(EditAnywhere)
		float TriggerMass = 20.f;

	AActor* ActorThatOpens = nullptr;
	AActor* Owner = nullptr;

		
	
};
