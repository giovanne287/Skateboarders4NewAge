// Fill out your copyright notice in the Description page of Project Settings.

#include "PointCollector.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Skateboarders4NAGameMode.h"

// Sets default values
APointCollector::APointCollector()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    // Create box collision and set as root
    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    RootComponent = CollisionBox;
    CollisionBox->SetCollisionProfileName(TEXT("Trigger"));

    // Bind begin overlap event
    CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APointCollector::OnOverlapBegin);

    // Bind end overlap event
    CollisionBox->OnComponentEndOverlap.AddDynamic(this, &APointCollector::OnOverlapEnd);


}
    // Initialize overlap bool
    bool bHasOverlapped = false;

// Called when the game starts or when spawned
void APointCollector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APointCollector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void APointCollector::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    // Check if the actor is valid and not him self
    if (OtherActor && (OtherActor != this))
    {
        // If the overlapped actor is a character
        ACharacter* PlayerCharacter = Cast<ACharacter>(OtherActor);
        if (PlayerCharacter && !bHasOverlapped)
        {
            // Get GameMode to add points
            ASkateboarders4NAGameMode* GM = Cast<ASkateboarders4NAGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
            if (GM)
            {
                GM->AddScore(PointsToAdd);
                bHasOverlapped = true;

                // Desabilitar a colisão até o personagem sair
                CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
            }
        }
    }
}

void APointCollector::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

    UE_LOG(LogTemp, Warning, TEXT("GGGGGGGGGGGGGGGG"));

    if (OtherActor && OtherActor != this)
    {
        UE_LOG(LogTemp, Warning, TEXT("DDDDDDDDDDDDDDDDD"));

        ACharacter* PlayerCharacter = Cast<ACharacter>(OtherActor);
        if (PlayerCharacter)
        {
            
            // Reabilitar a colisão quando o personagem sair
            GetWorld()->GetTimerManager().SetTimer(TimerHandle_ReenableCollision, this, &APointCollector::ReenableCollision, 0.5f, false);

            //CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

            //// Debug print: check if collision was re-enabled
            //if (CollisionBox->IsCollisionEnabled())
            //{
            //    UE_LOG(LogTemp, Warning, TEXT("Colisão reabilitada com sucesso."));
            //}
            //else
            //{
            //    UE_LOG(LogTemp, Warning, TEXT("Falha ao reabilitar a colisão."));
            //}

        }

    }
}

void APointCollector::ReenableCollision()
{
    UE_LOG(LogTemp, Warning, TEXT("Colisão reativada."));
    CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    bHasOverlapped = false;
}