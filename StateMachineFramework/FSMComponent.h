// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateBase.h"
#include "Components/ActorComponent.h"

#include "FSMComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FLATLINE_API UFSMComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY()
	UStateBase* CurrentState = nullptr;

	UPROPERTY()
	TMap<int,UStateBase*> StatesMap;

	int CurrentStateID = -100;

	

public:
	// Sets default values for this component's properties
	UFSMComponent();

	void SwitchState(int newStateID);

	void AddState(int ID,UStateBase * StateClass);

	int GetCurrentStateID() const
	{
		return CurrentStateID;
	}

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void SwitchOn(int newStateID);

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
