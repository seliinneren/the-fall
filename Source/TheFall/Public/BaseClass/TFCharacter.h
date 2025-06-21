// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/SaveActorInterface.h"
#include "TFCharacter.generated.h"

UCLASS()
class THEFALL_API ATFCharacter : public ACharacter, public ISaveActorInterface
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, meta = (AllowPrivateAccess = "true"))
	class UStatlineComponent* Statline;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, meta = (AllowPrivateAccess = "true"))
	FGuid SaveActorID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, meta = (AllowPrivateAccess = "true"))
	bool WasSpawned = false;

	virtual void BeginPlay() override;
	void HasJumped();
	bool CanJump() const;

	bool CanSprint() const;
	void SetSprinting(const bool& IsSprinting);
	void SetSneaking(const bool& IsSneaking);

public:

	ATFCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	FGuid GetActorSaveID_Implementation();
	FSaveActorData GetActorSaveData_Implementation();
	void SetActorGuid_Implementation(const FGuid& NewGuid);
};
