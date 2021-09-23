// Copyright (c) 2012-2021 Wojciech Figat. All rights reserved.

#pragma once

#if PLATFORM_GDK || USE_EDITOR

#include "Engine/Core/Config/PlatformSettingsBase.h"
#include "Engine/Core/Math/Color.h"

/// <summary>
/// GDK platform settings.
/// </summary>
API_CLASS(Namespace="FlaxEditor.Content.Settings") class FLAXENGINE_API GDKPlatformSettings : public SettingsBase
{
DECLARE_SCRIPTING_TYPE_MINIMAL(GDKPlatformSettings);
public:

    /// <summary>
    /// Game publisher identity name stored in game package manifest (for store).
    /// </summary>
    API_FIELD(Attributes="EditorOrder(100), EditorDisplay(\"General\")")
    String PublisherName;

    /// <summary>
    /// Game publisher display name stored in game package manifest (for UI).
    /// </summary>
    API_FIELD(Attributes="EditorOrder(110), EditorDisplay(\"General\")")
    String PublisherDisplayName;

    /// <summary>
    /// Application small logo texture of size 150x150 px (asset id).
    /// </summary>
    API_FIELD(Attributes="EditorOrder(200), CustomEditorAlias(\"FlaxEditor.CustomEditors.Editors.AssetRefEditor\"), AssetReference(typeof(Texture)), EditorDisplay(\"Visuals\")")
    Guid Square150x150Logo;

    /// <summary>
    /// Application large logo texture of size 480x480 px (asset id).
    /// </summary>
    API_FIELD(Attributes="EditorOrder(205), CustomEditorAlias(\"FlaxEditor.CustomEditors.Editors.AssetRefEditor\"), AssetReference(typeof(Texture)), EditorDisplay(\"Visuals\")")
    Guid Square480x480Logo;

    /// <summary>
    /// Application small logo texture of size 44x44 px (asset id).
    /// </summary>
    API_FIELD(Attributes="EditorOrder(210), CustomEditorAlias(\"FlaxEditor.CustomEditors.Editors.AssetRefEditor\"), AssetReference(typeof(Texture)), EditorDisplay(\"Visuals\")")
    Guid Square44x44Logo;

    /// <summary>
    /// Application splash screen texture (asset id).
    /// </summary>
    API_FIELD(Attributes="EditorOrder(220), CustomEditorAlias(\"FlaxEditor.CustomEditors.Editors.AssetRefEditor\"), AssetReference(typeof(Texture)), EditorDisplay(\"Visuals\")")
    Guid SplashScreenImage;

    /// <summary>
    /// Application store logo texture (asset id).
    /// </summary>
    API_FIELD(Attributes="EditorOrder(230), CustomEditorAlias(\"FlaxEditor.CustomEditors.Editors.AssetRefEditor\"), AssetReference(typeof(Texture)), EditorDisplay(\"Visuals\")")
    Guid StoreLogo;

    /// <summary>
    /// Application background color.
    /// </summary>
    API_FIELD(Attributes="EditorOrder(240), DefaultValue(typeof(Color), \"0,0,0,1\"), EditorDisplay(\"Visuals\")")
    Color BackgroundColor = Color::Black;

    /// <summary>
    /// Application foreground text theme (light or dark).
    /// </summary>
    API_FIELD(Attributes="EditorOrder(250), EditorDisplay(\"Visuals\")")
    String ForegroundText = TEXT("light");

    /// <summary>
    /// Specifies the Titles Xbox Live Title ID, used for identity with Xbox Live services (optional).
    /// </summary>
    API_FIELD(Attributes="EditorOrder(300), EditorDisplay(\"Xbox Live\")")
    String TitleId;

    /// <summary>
    /// Specifies the Titles Xbox Live Title ID, used for identity with Xbox Live services (optional).
    /// </summary>
    API_FIELD(Attributes="EditorOrder(310), EditorDisplay(\"Xbox Live\")")
    String StoreId;

    /// <summary>
    /// Specifies if the title requires Xbox Live connectivity in order to run (optional).
    /// </summary>
    API_FIELD(Attributes="EditorOrder(320), EditorDisplay(\"Xbox Live\")")
    bool RequiresXboxLive = false;

    /// <summary>
    /// Specifies if the Game DVR system component is enabled or not.
    /// </summary>
    API_FIELD(Attributes="EditorOrder(400), EditorDisplay(\"Media Capture\")")
    bool GameDVRSystemComponent = true;

    /// <summary>
    /// Specifies if broadcasting the title should be blocked or allowed.
    /// </summary>
    API_FIELD(Attributes="EditorOrder(410), EditorDisplay(\"Media Capture\")")
    bool BlockBroadcast  = false;

    /// <summary>
    /// Specifies if Game DVR of the title should be blocked or allowed.
    /// </summary>
    API_FIELD(Attributes="EditorOrder(420), EditorDisplay(\"Media Capture\")")
    bool BlockGameDVR  = false;

public:

    // [SettingsBase]
    void Deserialize(DeserializeStream& stream, ISerializeModifier* modifier) override
    {
        DESERIALIZE(PublisherName);
        DESERIALIZE(PublisherDisplayName);
        DESERIALIZE(Square150x150Logo);
        DESERIALIZE(Square480x480Logo);
        DESERIALIZE(Square44x44Logo);
        DESERIALIZE(SplashScreenImage);
        DESERIALIZE(StoreLogo);
        DESERIALIZE(BackgroundColor);
        DESERIALIZE(TitleId);
        DESERIALIZE(StoreId);
        DESERIALIZE(RequiresXboxLive);
        DESERIALIZE(GameDVRSystemComponent);
        DESERIALIZE(BlockBroadcast);
        DESERIALIZE(BlockGameDVR);
    }
};

#endif