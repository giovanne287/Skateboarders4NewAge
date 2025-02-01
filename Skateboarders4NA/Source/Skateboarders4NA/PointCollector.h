// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointCollector.generated.h"

class UBoxComponent;

UCLASS()
class SKATEBOARDERS4NA_API APointCollector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APointCollector();

	// Called every frame
	virtual void Tick(float DeltaTime) override;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    // Box collision component
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
        UBoxComponent* CollisionBox;

    // Points to add (Default = 1)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Points")
        int32 PointsToAdd = 1;

    // Timer to reenable collision
    FTimerHandle TimerHandle_ReenableCollision;
    void ReenableCollision();

    // Begin overlap
    UFUNCTION()
        void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
            bool bFromSweep, const FHitResult& SweepResult);

    // End Overlap
    UFUNCTION()
        void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};