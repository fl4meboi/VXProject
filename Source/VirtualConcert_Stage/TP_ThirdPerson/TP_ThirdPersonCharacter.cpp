// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_ThirdPersonCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "../ActorComponent/AkAudioComponent.h"
#include "../AudioSpectrum/MyAudioSynesthesia.h"
#include <../../Engine/Public/EngineUtils.h>
#include <../../Engine/Classes/Kismet/GameplayStatics.h>
#include "../DMX/DMX.h"
#include "../DMX/MySpotLightComponent.h"
#include "../MaterialActor/DisplayActor.h"
#include "../ActorComponent/MaterialComponent.h"
#include "../Dive/DiveLED.h"
#include "../Dive/DiveController.h"
#include "../AI/AI.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ATP_ThirdPersonCharacter

ATP_ThirdPersonCharacter::ATP_ThirdPersonCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	
	
	// MY CODE 
	GetCapsuleComponent()->SetCollisionProfileName(FName("ReactPlayer"));
	GetMesh()->SetCollisionProfileName(FName("NoCollision"));
	
	AkAudioComp = CreateDefaultSubobject<UAkAudioComponent>(TEXT("AkAudioComp"));
	AkAudioComp->SetupAttachment(GetMesh());
	// MY CODE 




}

void ATP_ThirdPersonCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
	
	
	//MY CODE//
#pragma region MyCode

	
	//BP_AudioSynesthesia 찾기
	for (TActorIterator<AMyAudioSynesthesia> it(GetWorld()); it; ++it)
	{
			AudioSynesthesia = *it;
	}

	//BP_DMX 찾기 , display 찾기 , DiveLed 찾기 , AI 찾기
	TArray<AActor*> AllActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), AllActors);
	for (auto TempActor : AllActors)
	{
		
		if (auto Temp = Cast<ADMX>(TempActor))
		{
			DmxObjects.Add(Temp);

		}
		else if (auto Temp2 = Cast<ADisplayActor>(TempActor))
		{
			DisplayActorObjects.Add(Temp2);

		}
		else if (auto Temp3 = Cast<ADiveController>(TempActor))
		{
			DiveControllObjects.Add(Temp3);
		}
		else if (auto Temp4 = Cast<AAI>(TempActor))
		{
			AIObjects.Add(Temp4);
		}
	}
#pragma endregion MyCode
	//MY CODE//









}


//MY CODE//
#pragma region MyCode
void ATP_ThirdPersonCharacter::UseNum1()
{
	/*for (auto TempObject : DmxObjects)
	{
		TempObject->SpotComp->SetClockLightColor();
	
	}*/
	


}

void ATP_ThirdPersonCharacter::UseNum2()
{
	/*GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Key 2"));
	for (auto TempObject : DmxObjects)
	{
		TempObject->SpotComp->TurnDownLight();
	}*/
	AkAudioComp->ActiveFish();
}

void ATP_ThirdPersonCharacter::UseNum3()
{
	/*for (auto TempObject : DmxObjects)
	{
		TempObject->SpotComp->SetUnClockLightColor();
	}*/
	AkAudioComp->ModifiedNiagara();

}

void ATP_ThirdPersonCharacter::UseNum4()
{
	/*GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Key 4"));
	for (auto TempObject : DmxObjects)
	{
		TempObject->SpotComp->TurnUnClockDirLight();
	}*/
	AkAudioComp->ActiveFirewoks();
	
}

void ATP_ThirdPersonCharacter::UseNum5()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Key 5"));
	AkAudioComp->ActiveFirewoks2();


}

void ATP_ThirdPersonCharacter::UseNum6()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Key 6"));

	/*for (auto TempObject : DmxObjects)
	{
		TempObject->SpotComp->TurnClockDirLight();
	}*/
	AkAudioComp->ActiveFirewoksDelay();

}

void ATP_ThirdPersonCharacter::UseNum7()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Key 7"));
	for (auto TempObject : DmxObjects)
	{
		TempObject->SpotComp->AddOuterAngle();
	}
}

void ATP_ThirdPersonCharacter::UseNum8()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Key 8"));
	for (auto TempObject : DmxObjects)
	{
		TempObject->SpotComp->TurnUpLight();
	}
}

void ATP_ThirdPersonCharacter::UseNum9()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Key 9"));
	for (auto TempObject : DmxObjects)
	{
		TempObject->SpotComp->SubOuterAngle();
	}
}

#pragma endregion MyCode
//MY CODE//
// flipflop 박긴 해야함.
void ATP_ThirdPersonCharacter::PlayMusic()
{
	
	AkAudioComp->PlayAkEvent();
	AudioSynesthesia->PlayMusic();
	for (auto TempActor : DisplayActorObjects)
	{
		TempActor->MatComp->OnEvent();
	}


	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("P"));



}

void ATP_ThirdPersonCharacter::RotateLED()
{
	for (auto TempObject : DiveControllObjects)
	{
		TempObject->RotateAllLED();

	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void ATP_ThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATP_ThirdPersonCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ATP_ThirdPersonCharacter::Look);

		//MY CODE//
#pragma region MyCode

		EnhancedInputComponent->BindAction(Num1Action, ETriggerEvent::Ongoing, this, &ATP_ThirdPersonCharacter::UseNum1);
		EnhancedInputComponent->BindAction(Num2Action, ETriggerEvent::Ongoing, this, &ATP_ThirdPersonCharacter::UseNum2);
		EnhancedInputComponent->BindAction(Num3Action, ETriggerEvent::Ongoing, this, &ATP_ThirdPersonCharacter::UseNum3);
		EnhancedInputComponent->BindAction(Num4Action, ETriggerEvent::Ongoing, this, &ATP_ThirdPersonCharacter::UseNum4);
		EnhancedInputComponent->BindAction(Num5Action, ETriggerEvent::Started, this, &ATP_ThirdPersonCharacter::UseNum5);
		EnhancedInputComponent->BindAction(Num6Action, ETriggerEvent::Ongoing, this, &ATP_ThirdPersonCharacter::UseNum6);
		EnhancedInputComponent->BindAction(Num7Action, ETriggerEvent::Ongoing, this, &ATP_ThirdPersonCharacter::UseNum7);
		EnhancedInputComponent->BindAction(Num8Action, ETriggerEvent::Ongoing, this, &ATP_ThirdPersonCharacter::UseNum8);
		EnhancedInputComponent->BindAction(Num9Action, ETriggerEvent::Ongoing, this, &ATP_ThirdPersonCharacter::UseNum9);


		EnhancedInputComponent->BindAction(PlayMusicAction, ETriggerEvent::Started, this, &ATP_ThirdPersonCharacter::PlayMusic);
#pragma endregion MyCode
		//MY CODE//


	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ATP_ThirdPersonCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ATP_ThirdPersonCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}