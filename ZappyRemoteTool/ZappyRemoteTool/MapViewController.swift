//
//  MapViewController.swift
//  ZappyRemoteTool
//
//  Created by Antoine Baché on 02/07/2017.
//  Copyright © 2017 Antoine Baché. All rights reserved.
//

import UIKit

class MapViewController: UIViewController {

    @IBOutlet weak var caseX: UITextField!
    @IBOutlet weak var caseY: UITextField!
    
    @IBAction func removeFood(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Removing food from " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " food"
            _ = NetworkManager.sharedInstance.send(msg: "map rm " + msg)
        }
    }

    @IBAction func removeLinemate(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Removing linemate from " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " linemate"
            _ = NetworkManager.sharedInstance.send(msg: "map rm " + msg)
        }
    }
    
    @IBAction func removeDeraumere(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Removing deraumere from " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " deraumere"
            _ = NetworkManager.sharedInstance.send(msg: "map rm " + msg)
        }
    }
    
    @IBAction func removeSibur(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Removing sibur from " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " sibur"
            _ = NetworkManager.sharedInstance.send(msg: "map rm " + msg)
        }
    }
    
    @IBAction func removeMendiane(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Removing mendiane from " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " mendiane"
            _ = NetworkManager.sharedInstance.send(msg: "map rm " + msg)
        }
    }
    
    @IBAction func RemovePhiras(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Removing phiras from " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " phiras"
            _ = NetworkManager.sharedInstance.send(msg: "map rm " + msg)
        }
    }
    
    @IBAction func removeThystame(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Removing thystame from " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " thystame"
            _ = NetworkManager.sharedInstance.send(msg: "map rm " + msg)
        }
    }
    
    
    @IBAction func addFood(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Adding food to " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " food"
            _ = NetworkManager.sharedInstance.send(msg: "map add " + msg)
        }
    }
    
    @IBAction func addLinemate(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Adding linemate to " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " linemate"
            _ = NetworkManager.sharedInstance.send(msg: "map add " + msg)
        }
    }
    
    @IBAction func addDeraumere(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Adding deraumere to " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " deraumere"
            _ = NetworkManager.sharedInstance.send(msg: "map add " + msg)
        }
    }

    @IBAction func addSibur(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Adding sibur to " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " sibur"
            _ = NetworkManager.sharedInstance.send(msg: "map add " + msg)
        }
    }
    
    @IBAction func addMendiane(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Adding mendiane to " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " mendiane"
            _ = NetworkManager.sharedInstance.send(msg: "map add " + msg)
        }
    }
    
    @IBAction func addPhiras(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Adding phiras to " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " phiras"
            _ = NetworkManager.sharedInstance.send(msg: "map add " + msg)
        }
    }
    
    @IBAction func addThystame(_ sender: Any) {
        if caseX.text != nil && caseY.text != nil {
            print("Adding thystame to " + caseX.text! + "x" + caseY.text!)
            let msg = caseX.text! + " " + caseY.text! + " thystame"
            _ = NetworkManager.sharedInstance.send(msg: "map add " + msg)
        }
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        let tap: UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(UIInputViewController.dismissKeyboard))
        view.addGestureRecognizer(tap)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func dismissKeyboard() {
        view.endEditing(true)
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
