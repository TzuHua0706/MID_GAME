<GameFile>
  <PropertyGroup Name="runner_trangle" Type="Node" ID="a1b82adc-1cc6-4959-90b7-f604a8dc582d" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="24" Speed="1.0000">
        <Timeline ActionTag="1665172317" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trangle01.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="3" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trangle02.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="6" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trangle03.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="9" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trangle04.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="12" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trangle05.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="15" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trangle06.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="18" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trangle07.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="21" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trangle08.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="24" Tween="False">
            <TextureFile Type="PlistSubImage" Path="trangle01.png" Plist="new character.plist" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Node" Tag="32" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="shadow" CanEdit="False" ActionTag="2130606189" Tag="74" IconVisible="False" LeftMargin="-59.5015" RightMargin="-58.4985" TopMargin="84.3285" BottomMargin="-113.3285" ctype="SpriteObjectData">
            <Size X="118.0000" Y="29.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="-0.5015" Y="-98.8285" />
            <Scale ScaleX="1.1000" ScaleY="1.1000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="cubershadow.png" Plist="scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="player" ActionTag="1665172317" Tag="34" IconVisible="False" LeftMargin="-120.5000" RightMargin="-120.5000" TopMargin="-105.0000" BottomMargin="-105.0000" ctype="SpriteObjectData">
            <Size X="241.0000" Y="210.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="trangle02.png" Plist="new character.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="sad" ActionTag="1998629199" VisibleForFrame="False" Tag="94" IconVisible="True" LeftMargin="4.1935" RightMargin="-4.1935" TopMargin="0.4948" BottomMargin="-0.4948" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="eyes_nomal" ActionTag="948991066" Tag="95" IconVisible="False" LeftMargin="-60.8389" RightMargin="-24.1611" TopMargin="-73.5897" BottomMargin="21.5897" ctype="SpriteObjectData">
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
              <AbstractNodeData Name="eyes_sad" ActionTag="-2011458674" Tag="96" IconVisible="False" LeftMargin="-58.7878" RightMargin="-24.2122" TopMargin="-73.6103" BottomMargin="47.6103" ctype="SpriteObjectData">
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
              <AbstractNodeData Name="mouth_sad" ActionTag="-1584661609" Tag="97" IconVisible="False" LeftMargin="-45.5224" RightMargin="-0.4776" TopMargin="-28.8769" BottomMargin="6.8769" ctype="SpriteObjectData">
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
            <Position X="4.1935" Y="-0.4948" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="happy" ActionTag="-1250002700" VisibleForFrame="False" Tag="91" IconVisible="True" LeftMargin="-18.4933" RightMargin="18.4933" TopMargin="-13.5843" BottomMargin="13.5843" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="eyes_happy" ActionTag="2128463934" Tag="92" IconVisible="False" LeftMargin="-38.4537" RightMargin="-46.5463" TopMargin="-59.4206" BottomMargin="7.4206" ctype="SpriteObjectData">
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
              <AbstractNodeData Name="mouth_happy" ActionTag="-1413706086" Tag="93" IconVisible="False" LeftMargin="-19.0562" RightMargin="-15.9438" TopMargin="-14.4234" BottomMargin="-6.5766" ctype="SpriteObjectData">
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
            <Position X="-18.4933" Y="13.5843" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="normal" ActionTag="-1397246288" Tag="88" IconVisible="True" LeftMargin="1.3730" RightMargin="-1.3730" TopMargin="6.9557" BottomMargin="-6.9557" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="cmouth1_2" ActionTag="478371099" Tag="89" IconVisible="False" LeftMargin="-40.3232" RightMargin="5.3232" TopMargin="-35.0908" BottomMargin="14.0908" ctype="SpriteObjectData">
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
              <AbstractNodeData Name="ceyes1_3" ActionTag="-647766617" Tag="90" IconVisible="False" LeftMargin="-57.9005" RightMargin="-27.0995" TopMargin="-80.2816" BottomMargin="28.2816" ctype="SpriteObjectData">
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
            <Position X="1.3730" Y="-6.9557" />
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