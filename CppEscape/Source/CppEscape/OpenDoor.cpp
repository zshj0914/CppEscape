
// Fill out your copyright notice in the Description page of Project Settings.

#include "CppEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...

	Owner = GetOwner();

	if (!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("%s missing PressurePlate"), *GetOwner()->GetName());
	}
	
}

//void UOpenDoor::OpenDoor()
//{
//
//	//Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
//
//	OnOpenRequest.Broadcast();
//}
//
//void UOpenDoor::CloseDoor()
//{
//
//	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
//}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	if (GetTotalMassOfActorsOnPlate() > TriggerMass) {
		OnOpen.Broadcast();
	}
	else
		OnClose.Broadcast();
	// ...
}

float UOpenDoor::GetTotalMassOfActorsOnPlate(){
	float TotalMass = 0.f;

	//Fina all the overlapping actors
	TArray<AActor*> OverlappingActors;

	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OverlappingActors);

	//Iterate through them adding their masses
	for (const auto& Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());
		UE_LOG(LogTemp, Warning, TEXT("Total Mass is : %f"), TotalMass);
	}

	return TotalMass;
}

