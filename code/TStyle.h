class TStyle : public TNamed, public TAttLine, public TAttFill, public TAttMarker, public TAttText {
  //...
   virtual Int_t    DistancetoPrimitive(Int_t px, Int_t py);
   Int_t            GetNdivisions(Option_t *axis="X") const;
   TAttText        *GetAttDate() {return &fAttDate;}
   Color_t          GetAxisColor(Option_t *axis="X") const;
   Color_t          GetLabelColor(Option_t *axis="X") const;
   Style_t          GetLabelFont(Option_t *axis="X") const;
   Float_t          GetLabelOffset(Option_t *axis="X") const;
   Float_t          GetLabelSize(Option_t *axis="X") const;
   Color_t          GetTitleColor(Option_t *axis="X") const;  //return axis title color of pad title color
   Style_t          GetTitleFont(Option_t *axis="X") const;   //return axis title font of pad title font
   Float_t          GetTitleOffset(Option_t *axis="X") const; //return axis title offset
   Float_t          GetTitleSize(Option_t *axis="X") const;   //return axis title size
   Float_t          GetTickLength(Option_t *axis="X") const;

   Float_t          GetBarOffset() const {return fBarOffset;}
   Float_t          GetBarWidth() const {return fBarWidth;}
   Int_t            GetDrawBorder() const {return fDrawBorder;}
   Float_t          GetEndErrorSize() const {return fEndErrorSize;}
   Float_t          GetErrorX() const {return fErrorX;}
   Bool_t           GetCanvasPreferGL() const {return fCanvasPreferGL;}
   Color_t          GetCanvasColor() const {return fCanvasColor;}
   Width_t          GetCanvasBorderSize() const {return fCanvasBorderSize;}
   Int_t            GetCanvasBorderMode() const {return fCanvasBorderMode;}
   Int_t            GetCanvasDefH() const      {return fCanvasDefH;}
   Int_t            GetCanvasDefW() const      {return fCanvasDefW;}
   Int_t            GetCanvasDefX() const      {return fCanvasDefX;}
   Int_t            GetCanvasDefY() const      {return fCanvasDefY;}
   Int_t            GetColorPalette(Int_t i) const;
   Int_t            GetColorModelPS() const    {return fColorModelPS;}
   Float_t          GetDateX()  const          {return fDateX;}
   Float_t          GetDateY() const           {return fDateY;}
   // ... 200 more functions ...
   void             SaveSource(const char *filename, Option_t *option=0);
   //...
};

