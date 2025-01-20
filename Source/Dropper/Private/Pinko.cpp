#include "Pinko.h"

#include "DropperGameInstance.h"
#include "Chaos/DebugDrawQueue.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

APinko::APinko()
{
	PrimaryActorTick.bCanEverTick = true;

	Inventory = CreateDefaultSubobject<UInventory>("Inventory");
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("CameraSpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500.f;
	SpringArm->bUsePawnControlRotation = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void APinko::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	UDropperGameInstance* DropperGameInstance = GetGameInstance<UDropperGameInstance>();
	
	if (!DropperGameInstance)
	{
		return;
	}

	UCapsuleComponent* Capsule = GetCapsuleComponent();
	if (!Capsule) return;
}

void APinko::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APinko::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APinko::SetMovementInput(const FVector2D& MovementVector)
{
	AddMovementInput(GetActorForwardVector(), MovementVector.Y);
	AddMovementInput(GetActorRightVector(), MovementVector.X);
}

void APinko::SetLookInput(const FVector2D& LookVector)
{
	AddControllerYawInput(LookVector.X);
	AddControllerPitchInput(LookVector.Y);
}

void APinko::StartSprinting()
{
	GetCharacterMovement()->MaxWalkSpeed = 3000.f;
}

void APinko::StopSprinting()
{
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
}

void APinko::ChangeItem()
{
	FString Label = Inventory->SetNextSlot();
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("You selected: %s"), *Label));
}

void APinko::DropCurrentItem()
{
	Inventory->DropCurrentItem(1, GetActorLocation() + (GetActorForwardVector()* 100));
}

void APinko::AddCoin()
{
	UDropperGameInstance* DropperGameInstance = GetGameInstance<UDropperGameInstance>();
	
	if (!DropperGameInstance)
	{
		return;
	}

	DropperGameInstance->SetCoinCollected();
}
