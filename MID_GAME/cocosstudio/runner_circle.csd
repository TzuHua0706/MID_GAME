<GameFile>
  <PropertyGroup Name="runner_circle" Type="Node" ID="5a353ba8-5e7a-4a36-8b01-5b7bd17251b1" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="24" Speed="1.0000">
        <Timeline ActionTag="665801134" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="PlistSubImage" Path="circle01.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="3" Tween="False">
            <TextureFile Type="PlistSubImage" Path="circle02.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="6" Tween="False">
            <TextureFile Type="PlistSubImage" Path="circle03.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="9" Tween="False">
            <TextureFile Type="PlistSubImage" Path="circle04.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="12" Tween="False">
            <TextureFile Type="PlistSubImage" Path="circle05.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="15" Tween="False">
            <TextureFile Type="PlistSubImage" Path="circle06.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="18" Tween="False">
            <TextureFile Type="PlistSubImage" Path="circle07.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="21" Tween="False">
            <TextureFile Type="PlistSubImage" Path="circle08.png" Plist="new character.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="24" Tween="False">
            <TextureFile Type="PlistSubImage" Path="circle01.png" Plist="new character.plist" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Node" Tag="30" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="shadow" CanEdit="False" ActionTag="-764791259" Tag="78" IconVisible="False" LeftMargin="-59.5015" RightMargin="-58.4985" TopMargin="85.5000" BottomMargin="-114.5000" ctype="SpriteObjectData">
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
          <AbstractNodeData Name="player" ActionTag="665801134" Tag="31" IconVisible="False" LeftMargin="-119.2120" RightMargin="-121.7880" TopMargin="-100.3608" BottomMargin="-109.6392" ctype="SpriteObjectData">
            <Size X="241.0000" Y="210.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1.2880" Y="-4.6392" />
            <Scale ScaleX="0.9500" ScaleY="0.9500" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="circle05.png" Plist="new character.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="sad" ActionTag="1080662768" VisibleForFrame="False" Tag="133" IconVisible="True" LeftMargin="0.4821" RightMargin="-0.4821" TopMargin="5.1340" BottomMargin="-5.1340" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="eyes_nomal" ActionTag="1455986736" Tag="134" IconVisible="False" LeftMargin="-60.8389" RightMargin="-24.1611" TopMargin="-73.5897" BottomMargin="21.5897" ctype="SpriteObjectData">
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
              <AbstractNodeData Name="eyes_sad" ActionTag="-1228001985" Tag="135" IconVisible="False" LeftMargin="-58.7878" RightMargin="-24.2122" TopMargin="-73.6103" BottomMargin="47.6103" ctype="SpriteObjectData">
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
              <AbstractNodeData Name="mouth_sad" ActionTag="-1997055035" Tag="136" IconVisible="False" LeftMargin="-45.5224" RightMargin="-0.4776" TopMargin="-28.8769" BottomMargin="6.8769" ctype="SpriteObjectData">
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
            <Position X="0.4821" Y="-5.1340" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="happy" ActionTag="1089621481" VisibleForFrame="False" Tag="130" IconVisible="True" LeftMargin="-22.2046" RightMargin="22.2046" TopMargin="-8.9451" BottomMargin="8.9451" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="eyes_happy" ActionTag="-1400338679" Tag="131" IconVisible="False" LeftMargin="-38.4537" RightMargin="-46.5463" TopMargin="-59.4206" BottomMargin="7.4206" ctype="SpriteObjectData">
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
              <AbstractNodeData Name="mouth_happy" ActionTag="1527246745" Tag="132" IconVisible="False" LeftMargin="-19.0562" RightMargin="-15.9438" TopMargin="-14.4234" BottomMargin="-6.5766" ctype="SpriteObjectData">
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
            <Position X="-22.2046" Y="8.9451" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="normal" ActionTag="2073025017" Tag="127" IconVisible="True" LeftMargin="-2.3383" RightMargin="2.3383" TopMargin="11.5949" BottomMargin="-11.5949" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="cmouth1_2" ActionTag="10143412" Tag="128" IconVisible="False" LeftMargin="-40.3232" RightMargin="5.3232" TopMargin="-35.0908" BottomMargin="14.0908" ctype="SpriteObjectData">
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
              <AbstractNodeData Name="ceyes1_3" ActionTag="1685951964" Tag="129" IconVisible="False" LeftMargin="-57.9005" RightMargin="-27.0995" TopMargin="-80.2816" BottomMargin="28.2816" ctype="SpriteObjectData">
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
            <Position X="-2.3383" Y="-11.5949" />
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