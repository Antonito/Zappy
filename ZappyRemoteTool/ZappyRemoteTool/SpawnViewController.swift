//
//  SpawnViewController.swift
//  ZappyRemoteTool
//
//  Created by Antoine Baché on 02/07/2017.
//  Copyright © 2017 Antoine Baché. All rights reserved.
//

import UIKit

class SpawnViewController: UIViewController {

    @IBAction func spawnRandomAction(_ sender: Any) {
        print("Spawn random resource")
        _ = NetworkManager.sharedInstance.send(msg: "spawn rand")
    }

    @IBAction func spawnLinemateAction(_ sender: Any) {
        print("Spawn linemate resource")
        _ = NetworkManager.sharedInstance.send(msg: "spawn linemate")
    }
    
    @IBAction func spawnPhirasAction(_ sender: Any) {
        print("Spawn phiras resource")
        _ = NetworkManager.sharedInstance.send(msg: "spawn phiras")
    }
    
    @IBAction func spawnFoodAction(_ sender: Any) {
        print("Spawn food resource")
        _ = NetworkManager.sharedInstance.send(msg: "spawn food")
    }
    
    @IBAction func spawnDeraumereAction(_ sender: Any) {
        print("Spawn deraumere resource")
        _ = NetworkManager.sharedInstance.send(msg: "spawn deraumere")
    }
    
    @IBAction func spawnThystameAction(_ sender: Any) {
        print("Spawn thystame resource")
        _ = NetworkManager.sharedInstance.send(msg: "spawn thystame")
    }
    
    @IBAction func spawnSiburAction(_ sender: Any) {
        print("Spawn sibur resource")
        _ = NetworkManager.sharedInstance.send(msg: "spawn sibur")
    }
    
    @IBAction func spawnMendianeAction(_ sender: Any) {
        print("Spawn mendiane resource")
        _ = NetworkManager.sharedInstance.send(msg: "spawn mendiane")
    }
    
    @IBAction func spawnEggAction(_ sender: Any) {
        print("Spawn egg")
        _ = NetworkManager.sharedInstance.send(msg: "spawn egg")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
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
