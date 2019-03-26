import { Component, OnInit } from '@angular/core';
import { FormGroup, FormControl, Validators, } from '@angular/forms';
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent implements OnInit{
  title = 'dynamicform';
  mymodel = true;

  device: Device[] = [
    {value: 1, name: '12 CLass'},
    {value: 2, name: '11 Class'},
    {value: 3, name: '10 Class'}
  ];
  twelveForm = new FormGroup({
    phy1: new FormControl('',Validators.required),
    chem1: new FormControl('',Validators.required),
    mat1 : new FormControl('',Validators.required)
  })

  elevenForm = new FormGroup({
    phy2: new FormControl('',Validators.required),
    chem2: new FormControl('',Validators.required),
    mat2: new FormControl('',Validators.required)
  })

  tenForm =  new FormGroup({
    phy3: new FormControl('',Validators.required),
    chem3: new FormControl('',Validators.required),
    mat3: new FormControl('',Validators.required)
  })

  devices = [];

  add_marksheet(type: number)
  {
    if(type === 1)
    {
      this.devices.push(new Twelve(this.twelveForm.value.phy1, this.twelveForm.value.chem1, this.twelveForm.value.mat1));
      console.log(this.twelveForm);
    }
    else if(type === 2)
    {
      this.devices.push(new Eleven(this.elevenForm.value.phy2, this.elevenForm.value.chem2, this.elevenForm.value.mat2));
      console.log(this.elevenForm);
    }
    else if(type === 3)
    {
      this.devices.push(new Ten(this.tenForm.value.phy3, this.tenForm.value.chem3, this.tenForm.value.mat3));
      console.log(this.tenForm);
    }
    console.log(this.devices)
  }
  // clearform(){
  //   (<HTMLFormElement>document.getElementById("Login")).reset();
  //  }

  ngOnInit()
  {

  }

} // end of appcompnet class


class Device {
    value:number;
    name:string;
}

class Twelve {
  type: number;
  phy1: number;
  chem1: number;
  mat1: number;
  constructor(Phy1: number, Chem1: number, Mat1: number)
  {
    this.type = 1;
    this.phy1 = Phy1;
    this.chem1 = Chem1;
    this.mat1 = Mat1;
  }
}

class Eleven {
  type: number;
  phy2: number;
  chem2: number;
  mat2: number;
  constructor(Phy2: number, Chem2: number, Mat2: number)
  {
    this.type = 2;
    this.phy2 = Phy2;
    this.chem2 = Chem2;
    this.mat2 = Mat2;
  }
}

class Ten{
  type: number;
  phy3: number;
  chem3: number;
  mat3: number;
  constructor(Phy3: number, Chem3: number, Mat3: number)
  {
    this.type = 3;
    this.phy3 = Phy3;
    this.chem3 = Chem3;
    this.mat3 = Mat3;
  }
}
