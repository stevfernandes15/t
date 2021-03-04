MODEL
public function data_siswa_perkelas(){
        $query = $this->db->select('ds.nis, s.nama_siswa, s.alamat, s.no_hp, s.password, s.jenis_kelamin')
            ->from('detail_siswa AS ds')
            ->join('kelas AS k', 'k.id_kelas = ds.id_kelas')
            ->join('jurusan AS j', 'j.id_jurusan = ds.id_jurusan')
            ->join('tahun_ajaran AS t', 't.id_tahun_ajaran = ds.id_tahun_ajaran')
            ->join('siswa AS s', 's.nis = ds.nis')
            ->where('ds.id_kelas = k.id_kelas')
            ->where('ds.id_jurusan = j.id_jurusan')
            ->where('ds.id_tahun_ajaran = t.id_tahun_ajaran')
            ->get();
        return $query;
    return $query;
    }
    
    
    
    VIEW
    <!-- Content Body Start -->
<div class="content-body">

<!-- Page Headings Start -->
<div class="row justify-content-between align-items-center mb-10">
    <!-- Page Heading Start -->
    <div class="col-12 col-lg-auto mb-20">
        <div class="page-heading">
            <h3>Dashboard<span>/ Data Siswa</span></h3>
        </div>
    </div><!-- Page Heading End -->
</div><!-- Page Headings End -->
<?php 
    if($this->session->flashdata('msg')){
        echo $this->session->flashdata('msg');
    } 
?>
<div class="row">
    <!--Order List Start-->
<div class="col-12 col-sm-8">
    <h5 class="title">Jumlah Siswa : 
    <?php 
    $query = $this->db->get('siswa');
        echo $query->num_rows(); 
    ?>
    </h5>
    <button class="button button-primary button-outline" 
    onclick="window.location.href='<?php echo site_url('tambahsiswa');?>';">Tambah Siswa Baru
    </button>
    </div>
    <div class="col-12">
        <div class="table-responsive">
            <table class="table table-bordered data-table data-table-default" id="testing">
                <thead>
                    <tr>
                        <th>No.</th>
                        <th>NIS</th>
                        <th>Nama Siswa</th>
                        <th>Jurusan</th>
                        <th>Semester</th>
                        <th>Tahun Ajaran</th>
                        <th>Alamat</th>
                        <th>Nomor HP</th>
                        <th>Password</th>
                        <th>Jenis Kelamin</th>
                        <th>Aksi</th>
                    </tr>
                </thead>
                <tbody>
                <?php
                $no = 1;
                foreach ($perkelas as $data){
                ?>
                    <tr>
                        <td><?php echo $no++;?></td>
                        <td><?php echo $data->nis;?></td>
                        <td><?php echo $data->nama_siswa;?></td>
                        <td><?php echo $data->nama_jurusan;?></td>
                        <td>-</td>
                        <td>-</td>
                        <td><?php echo $data->alamat;?></td>
                        <td><?php echo $data->no_hp;?></td>
                        <td>
                        <?php 
                            $disallowed = array('password'=>$data->password);
                            echo word_censor($data->password, $disallowed, '***********');
                        ?>
                        </td>
                        <td>
                        <?php if($data->jenis_kelamin == 'lakilaki'):?>
                        Laki-Laki
                        <?php else: ?>
                        Perempuan
                        <?php endif;?>
                        </td>
                        <td class="action h4">
                            <div class="table-action-buttons">
                                <a href="<?php echo site_url('ubahsiswa/'.$data->nis)?>" class="edit button button-box button-xs button-info">
                                    <i class="zmdi zmdi-edit"></i>
                                </a>
                                <button onclick="window.location.href='<?php echo site_url('hapussiswa/'.$data->nis)?>';" 
                                class="sweetalert sweetalert-multiple button button-box button-xs button-danger"><i class="zmdi zmdi-delete"></i>
                                </button>
                            </div>
                        </td>
                    </tr>
                    <?php }?>
                </tbody>
            </table>
        </div>
    </div>
    <!--Order List End-->
</div>
</div><!-- Content Body End -->
