class TStyle : public TNamed, 
  public TAttLine, 
  public TAttFill, 
  public TAttMarker, 
  public TAttText {
  //...
   virtual Int_t    DistancetoPrimitive(Int_t px, 
                                        Int_t py);
   Int_t            GetNdivisions(Option_t *) const;
   TAttText        *GetAttDate() ;
   Color_t          GetAxisColor(Option_t *) const;
   Color_t          GetLabelColor(Option_t *) const;
   Style_t          GetLabelFont(Option_t *) const;
   Float_t          GetLabelOffset(Option_t *) const;
   Float_t          GetLabelSize(Option_t *) const;
   Color_t          GetTitleColor(Option_t *) const; 
   Style_t          GetTitleFont(Option_t *) const;  
   Float_t          GetTitleOffset(Option_t *) const;
   Float_t          GetTitleSize(Option_t *) const;  
   Float_t          GetTickLength(Option_t *) const;

   Float_t          GetBarOffset() const ;
   Float_t          GetBarWidth() const ;
   Int_t            GetDrawBorder() const ;
   Float_t          GetEndErrorSize() const ;
   Float_t          GetErrorX() const ;
   Bool_t           GetCanvasPreferGL() const ;
   Color_t          GetCanvasColor() const ;
   Width_t          GetCanvasBorderSize() const ;
   Int_t            GetCanvasBorderMode() const ;
   Int_t            GetCanvasDefH() const      ;
   Int_t            GetCanvasDefW() const      ;
   Int_t            GetCanvasDefX() const      ;
   Int_t            GetCanvasDefY() const      ;
   Int_t            GetColorPalette(Int_t i) const;
   Int_t            GetColorModelPS() const    ;
   Float_t          GetDateX()  const          ;
   Float_t          GetDateY() const           ;
   // ... 200 more functions including 
   //     the setters for the above getters ...
   void             SaveSource(const char *filename, 
                               Option_t *option=0);
   //...
};

