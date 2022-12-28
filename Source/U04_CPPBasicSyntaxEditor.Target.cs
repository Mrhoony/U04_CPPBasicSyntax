// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class U04_CPPBasicSyntaxEditorTarget : TargetRules
{
	public U04_CPPBasicSyntaxEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "U04_CPPBasicSyntax" } );
	}
}
