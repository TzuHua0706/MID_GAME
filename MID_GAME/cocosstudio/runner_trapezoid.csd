<GameFile>
  <PropertyGroup Name="runner_trapezoid" Type="Node" ID="5456ed5e-99dd-4935-989d-07a966b5f15a" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="24" Speed="1.0000">
        <Timeline ActionTag="-1615364148" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trapezoid01.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="3" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trapezoid02.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="6" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trapezoid03.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="9" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trapezoid04.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="12" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trapezoid05.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="15" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trapezoid06.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="18" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trapezoid07.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="21" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trapezoid08.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="24" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trapezoid01.png" Plist="new character.plist" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Node" Tag="33" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="shadow" CanEdit="False" ActionTag="-812802843" Tag="76" IconVisible="False" LeftMargin="-59.5015" RightMargin="-58.4985" TopMargin="85.5000" BottomMargin="-114.5000" ctype="SpriteObjectData">
            <Size X="118.0000" Y="29.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-0.5015" Y="-100.0000" />
            <Scale ScaleX="1.1000" ScaleY="1.1000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="cubershadow.png" Plist="scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="player" ActionTag="-1615364148" Tag="37" IconVisible="False" LeftMargin="-124.5028" RightMargin="-116.4972" TopMargin="-112.0023" BottomMargin="-97.9977" ctype="SpriteObjectData">
            <Size X="241.0000" Y="210.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-4.0028" Y="7.0023" />
            <Scale ScaleX="1.0500" ScaleY="1.0500" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="trapezoid03.png" Plist="new character.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="sad" ActionTag="-933320703" VisibleForFrame="False" Tag="75" IconVisible="True" LeftMargin="-4.1572" RightMargin="4.1572" TopMargin="3.2782" BottomMargin="-3.2782" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="eyes_nomal" ActionTag="-1432171486" Tag="76" IconVisible="False" LeftMargin="-60.8389" RightMargin="-24.1611" TopMargin="-73.5897" BottomMargin="21.5897" ctype="SpriteObjectData">
                <Size X="85.0000" Y="52.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-18.3389" Y="47.5897" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="PlistSubImage" Path="ceyes1.png" Plist="scene101.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="eyes_sad" ActionTag="-2107212033" Tag="77" IconVisible="False" LeftMargin="-58.7878" RightMargin="-24.2122" TopMargin="-73.6103" BottomMargin="47.6103" ctype="SpriteObjectData">
                <Size X="83.0000" Y="26.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-17.2878" Y="60.6103" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="PlistSubImage" Path="ceyes2.png" Plist="scene101.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="mouth_sad" ActionTag="-1328711093" Tag="78" IconVisible="False" LeftMargin="-45.5224" RightMargin="-0.4776" TopMargin="-28.8769" BottomMargin="6.8769" ctype="SpriteObjectData">
                <Size X="46.0000" Y="22.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-22.5224" Y="17.8769" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="PlistSubImage" Path="cmouth2.png" Plist="scene101.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="-4.1572" Y="-3.2782" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="happy" ActionTag="-1395976715" VisibleForFrame="False" Tag="72" IconVisible="True" LeftMargin="-26.8440" RightMargin="26.8440" TopMargin="-10.8008" BottomMargin="10.8008" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="eyes_happy" ActionTag="-987438329" Tag="73" IconVisible="False" LeftMargin="-38.4537" RightMargin="-46.5463" TopMargin="-59.4206" BottomMargin="7.4206" ctype="SpriteObjectData">
                <Size X="85.0000" Y="52.0000" />
                <AnchorPoint ScaleX="0.4000" ScaleY="0.5000" />
                <Position X="-4.4537" Y="33.4206" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="PlistSubImage" Path="ceyes3.png" Plist="scene101.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="mouth_happy" ActionTag="-221314052" Tag="74" IconVisible="False" LeftMargin="-19.0562" RightMargin="-15.9438" TopMargin="-14.4234" BottomMargin="-6.5766" ctype="SpriteObjectData">
                <Size X="35.0000" Y="21.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-1.5562" Y="3.9234" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="PlistSubImage" Path="cmouth1.png" Plist="scene101.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="-26.8440" Y="10.8008" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="normal" ActionTag="-1606411251" Tag="69" IconVisible="True" LeftMargin="-6.9777" RightMargin="6.9777" TopMargin="9.7391" BottomMargin="-9.7391" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="cmouth1_2" ActionTag="-774370017" Tag="70" IconVisible="False" LeftMargin="-40.3232" RightMargin="5.3232" TopMargin="-35.0908" BottomMargin="14.0908" ctype="SpriteObjectData">
                <Size X="35.0000" Y="21.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-22.8232" Y="24.5908" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="PlistSubImage" Path="cmouth1.png" Plist="scene101.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="ceyes1_3" ActionTag="1987779527" Tag="71" IconVisible="False" LeftMargin="-57.9005" RightMargin="-27.0995" TopMargin="-80.2816" BottomMargin="28.2816" ctype="SpriteObjectData">
                <Size X="85.0000" Y="52.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-15.4005" Y="54.2816" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="PlistSubImage" Path="ceyes1.png" Plist="scene101.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="-6.9777" Y="-9.7391" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>