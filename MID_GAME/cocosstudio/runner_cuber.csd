<GameFile>
  <PropertyGroup Name="runner_cuber" Type="Node" ID="4f7c0063-174c-41af-9ad5-102bf8d69e30" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="24" Speed="1.0000">
        <Timeline ActionTag="-1631014451" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber01.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="3" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber02.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="6" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber03.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="9" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber04.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="12" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber05.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="15" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber06.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="18" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber07.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="21" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber08.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="24" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber01.png" Plist="scene101.plist" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Node" Tag="29" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="shadow" ActionTag="-448972639" Tag="77" IconVisible="False" LeftMargin="-59.5015" RightMargin="-58.4985" TopMargin="85.5000" BottomMargin="-114.5000" ctype="SpriteObjectData">
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
          <AbstractNodeData Name="player" ActionTag="-1631014451" Tag="35" IconVisible="False" LeftMargin="-120.5000" RightMargin="-120.5000" TopMargin="-105.0000" BottomMargin="-105.0000" ctype="SpriteObjectData">
            <Size X="241.0000" Y="210.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="cuber07.png" Plist="scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="sad" ActionTag="-718370652" VisibleForFrame="False" Tag="56" IconVisible="True" LeftMargin="-2.3013" RightMargin="2.3013" TopMargin="-3.2166" BottomMargin="3.2166" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="eyes_nomal" ActionTag="1396912793" Tag="108" IconVisible="False" LeftMargin="-60.8389" RightMargin="-24.1611" TopMargin="-73.5897" BottomMargin="21.5897" ctype="SpriteObjectData">
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
              <AbstractNodeData Name="eyes_sad" ActionTag="-16971297" Tag="110" IconVisible="False" LeftMargin="-58.7878" RightMargin="-24.2122" TopMargin="-73.6103" BottomMargin="47.6103" ctype="SpriteObjectData">
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
              <AbstractNodeData Name="mouth_sad" ActionTag="1131667534" Tag="116" IconVisible="False" LeftMargin="-45.5224" RightMargin="-0.4776" TopMargin="-28.8769" BottomMargin="6.8769" ctype="SpriteObjectData">
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
            <Position X="-2.3013" Y="3.2166" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="happy" ActionTag="-315584468" VisibleForFrame="False" Tag="55" IconVisible="True" LeftMargin="-24.9880" RightMargin="24.9880" TopMargin="-17.2957" BottomMargin="17.2957" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="eyes_happy" ActionTag="-486303966" Tag="111" IconVisible="False" LeftMargin="-38.4537" RightMargin="-46.5463" TopMargin="-59.4206" BottomMargin="7.4206" ctype="SpriteObjectData">
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
              <AbstractNodeData Name="mouth_happy" ActionTag="682374273" Tag="117" IconVisible="False" LeftMargin="-19.0562" RightMargin="-15.9438" TopMargin="-14.4234" BottomMargin="-6.5766" ctype="SpriteObjectData">
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
            <Position X="-24.9880" Y="17.2957" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="normal" ActionTag="1257727567" Tag="57" IconVisible="True" LeftMargin="-5.1218" RightMargin="5.1218" TopMargin="3.2442" BottomMargin="-3.2442" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="cmouth1_2" ActionTag="-2009386583" Tag="58" IconVisible="False" LeftMargin="-40.3232" RightMargin="5.3232" TopMargin="-35.0908" BottomMargin="14.0908" ctype="SpriteObjectData">
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
              <AbstractNodeData Name="ceyes1_3" ActionTag="-937077643" Tag="59" IconVisible="False" LeftMargin="-57.9005" RightMargin="-27.0995" TopMargin="-80.2816" BottomMargin="28.2816" ctype="SpriteObjectData">
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
            <Position X="-5.1218" Y="-3.2442" />
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