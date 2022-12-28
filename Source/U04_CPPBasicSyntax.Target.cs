// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class U04_CPPBasicSyntaxTarget : TargetRules
{
	public U04_CPPBasicSyntaxTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "U04_CPPBasicSyntax" } );
	}
}
